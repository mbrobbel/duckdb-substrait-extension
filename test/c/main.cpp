#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "test_helpers.hpp"

int main(int argc, char* argv[]) {
	duckdb::string error;
	if (!duckdb::PrepareTempDir(error)) {
		std::cerr << error << std::endl;
		return 1;
	}
	auto result = Catch::Session().run(argc, argv);
	duckdb::DestroyTempDir(result == 0);
	return result;
}
