pipeline{
    agent any
    stages{
        stage('Checkout'){l
            steps{
                checkout scm
            }
        }
        stage('Análise estática') {
            steps {
                sh 'cppcheck --enable=warning src/'
            }
        }
        stage('Build') {
            steps {
                sh 'cmake -S . -B build'
                sh 'cmake --build build'
            }
        }
    }
}