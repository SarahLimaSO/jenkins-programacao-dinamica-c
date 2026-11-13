pipeline{
    agent any

    triggers{
        cron("9 0 * * 1-5")
    }

    stages{
        stage('Checkout'){
            steps{
                checkout scm
            }
        }
        stage('Análise estática'){
            steps {
                sh 'cppcheck --enable=all --inconclusive --std=c11 -I include src/ include/'
            }
        }
        stage('Build'){
            steps {
                sh 'cmake -S . -B build'
                sh 'cmake --build build'
            }
        }
        stage('Test'){
            steps{
                catchError(buildResult: 'UNSTABLE', stageResult: 'FAILURE') {
                    sh 'ctest --test-dir build --output-on-failure'
                }
            }
        }
    }
}