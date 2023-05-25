#include "mpi_lib.h"

void Init(int* argc, char*** argv) {
	MPI_Init(argc, argv);
}

void Final() {
	cout << "The End of the process" << endl;
	MPI_Finalize();
}

void Sender(int count, MPI_Datatype datatype, int dest, int msgtag, MPI_Comm comm, MPI_Request* request, int rank) {
	int buf = rank + 50;
	MPI_Isend(&buf, count, datatype, dest, msgtag, comm, request);
	MPI_Barrier(MPI_COMM_WORLD);
	cout << "This Process " << rank << " send " << buf << " to this " << dest << endl;
}

void Receiver(int buf, int count, MPI_Datatype datatype, int source, int msgtag, MPI_Comm comm, MPI_Request* request, int rank) {
	MPI_Irecv(&buf, count, datatype, source, msgtag, comm, request);
	MPI_Barrier(MPI_COMM_WORLD);
	cout << "This Process " << rank << " receive message " << buf  <<endl;
}
void Wait(MPI_Request* request, MPI_Status* status) {
	MPI_Wait(request, status);
}
