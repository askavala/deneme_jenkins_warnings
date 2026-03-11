pipeline {
    agent {
        docker { 
            image 'maven:3.9-eclipse-temurin-17' 
            args '-u root'
        }
    }

    stages {
        stage('Checkout') {
            steps {
                // Pulls the code from the GitHub repository configured in the Jenkins job
                checkout scm
            }
        }

        stage('Compile & Log') {
            steps {
                script {
                    // Compiling the files pulled directly from GitHub
                    sh 'gcc -Wall main.c -o program > gcc_build.log 2>&1 || true'
                    sh 'javac -Xlint:all App.java > java_build.log 2>&1 || true'
                }
            }
        }

        stage('Quality Analysis') { 
            steps {
                echo "🔍 Updating Dashboard..."
                recordIssues([
                    enabledForFailure: true,
                    tools: [
                        gcc(pattern: 'gcc_build.log', id: 'gcc-analysis', name: 'C Errors'),
                        java(pattern: 'java_build.log', id: 'java-analysis', name: 'Java Errors')
                    ],
                    trendChartType: 'AGGREGATION_TOOLS'
                ])
            }
        }
    }

    post {
        always {
            // Built-in plugin to clean the entire workspace cleanly
            cleanWs()
        }
    }
}
