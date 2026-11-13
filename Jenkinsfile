pipeline{
    agent any

    triggers{
        cron("17 0 * * 1-5")
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
                sh 'cmake -S . -B build -DENABLE_COVERAGE=ON'
                sh 'cmake --build build'
            }
        }
        stage('Test'){
            steps{
                sh 'find build -type f -name "*.gcda" -delete'
                
                catchError(buildResult: 'UNSTABLE', stageResult: 'FAILURE') {
                    sh 'ctest --test-dir build --output-on-failure'
                }
            }
        }
        stage('Code Coverage'){
            when {
                expression {
                    currentBuild.currentResult == 'SUCCESS'
                }
            }
            steps{
                sh 'mkdir -p coverage'

                sh '''
                    gcovr --root . \
                        --filter 'src/' \
                        --print-summary \
                        --html-details coverage/index.html \
                        build
                '''

                archiveArtifacts artifacts: 'coverage/**',
                                fingerprint: true
            }
        }
    }
}