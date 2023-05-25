#include "mpi_lib.h"
#include <iostream>

int main(int argc, char** argv) {
    Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int message = 0;
    MPI_Request request;

    Sender(1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD, &request, rank);
    Receiver(message, 1, MPI_INT, (rank - 1 + size) % size, 0, MPI_COMM_WORLD, &request, rank);

    Wait(&request, MPI_STATUS_IGNORE);

    Final();
    return 0;
}
