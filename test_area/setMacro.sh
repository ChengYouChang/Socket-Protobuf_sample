alias pt="clear; g++ -o pthread_example.out basic_pthread_example.cpp -lpthread; ./pthread_example.out; rm pthread_example.out"
alias server="clear; g++ -o server.out server_pthread.cpp fakePB.pb.cc -lpthread -lprotobuf; ./server.out; rm server.out"
alias client="clear; g++ -o client.out client_pthread.cpp fakePB.pb.cc -lpthread -lprotobuf; ./client.out; rm client.out"
alias clean="rm *.out"