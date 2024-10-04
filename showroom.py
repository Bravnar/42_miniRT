import subprocess
import os
from concurrent.futures import ThreadPoolExecutor, as_completed

# Function to execute a command with a file as parameter
def run_executable(executable, file, dir):
	try:
		# Running the executable with the file as parameter
		result = subprocess.run([executable, os.path.join(dir, file)], capture_output=True, text=True)

		# Print or return the output (or handle errors)
		if result.returncode == 0:
			return f"Execution successful for file {file}: {result.stdout}"
		else:
			return f"Error executing file {file}: {result.stderr}"
	except Exception as e:
		return f"Failed to execute {file}: {str(e)}"

# Main function to execute the files in parallel
def execute_files(executable, file_list, dir):
	# Create a thread pool for parallel execution
	with ThreadPoolExecutor(max_workers=len(file_list)) as executor:
		# Submit tasks to the thread pool
		futures = [executor.submit(run_executable, executable, file, dir) for file in file_list]

		# Process results as they complete
		for future in as_completed(futures):
			print(future.result())  # Print the result of the execution

if __name__ == "__main__":
	# Path to the executable
	if os.path.exists("./miniRT"):
		executable = "./miniRT"
		file_list =  os.listdir('test_rt/showroom_std')
		dir = 'test_rt/showroom_std'
		execute_files(executable, file_list, dir)
	elif os.path.exists("./miniRT_bonus"):
		executable = executable = "./miniRT_bonus"
		file_list =  os.listdir('test_rt/showroom_bonus')
		dir = 'test_rt/showroom_bonus'
		execute_files(executable, file_list, dir)
