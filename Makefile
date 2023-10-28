CC=gcc

FLAGS=-O3
BLAS_FLAGS=-L/opt/homebrew/opt/openblas/lib -I/opt/homebrew/opt/openblas/include -lblas -lm
ATLAS_FLAGS=-L/opt/homebrew/opt/atlas/lib -I/opt/homebrew/opt/atlas/include -latlas -lblas -lm
INCLUDE=-Iinclude

BIN_DIR=bin
TEST_DIR=tests
BENCHMARK_DIR=benchmark

test: test_atlas_block_mm test_atlas_mm test_blas_block_mm test_blas_mm test_manual_block_mm

test_atlas_block_mm:
	$(CC) $(FLAGS) -o $(BIN_DIR)/test_atlas_block_mm $(TEST_DIR)/test_atlas_block_mm.c $(INCLUDE) $(ATLAS_FLAGS)

test_atlas_mm:
	$(CC) $(FLAGS) -o $(BIN_DIR)/test_atlas_mm $(TEST_DIR)/test_atlas_mm.c $(INCLUDE) $(ATLAS_FLAGS)

test_blas_block_mm:
	$(CC) $(FLAGS) -o $(BIN_DIR)/test_blas_block_mm $(TEST_DIR)/test_blas_block_mm.c $(INCLUDE) $(BLAS_FLAGS)

test_blas_mm:
	$(CC) $(FLAGS) -o $(BIN_DIR)/test_blas_mm $(TEST_DIR)/test_blas_mm.c $(INCLUDE) $(BLAS_FLAGS)

test_manual_block_mm:
	$(CC) $(FLAGS) -o $(BIN_DIR)/test_manual_block_mm $(TEST_DIR)/test_manual_block_mm.c $(INCLUDE)

benchmark: benchmark_blas_non_block benchmark_atlas_block

benchmark_blas_non_block:
	$(CC) $(FLAGS) -o $(BIN_DIR)/benchmark_blas_non_block  $(BENCHMARK_DIR)/benchmark_blas_non_block.c $(INCLUDE) $(BLAS_FLAGS)

benchmark_atlas_block:
	$(CC) $(FLAGS) -o $(BIN_DIR)/benchmark_atlas_block  $(BENCHMARK_DIR)/benchmark_atlas_block.c $(INCLUDE) $(BLAS_FLAGS)

clean:
	rm $(BIN_DIR)/*
