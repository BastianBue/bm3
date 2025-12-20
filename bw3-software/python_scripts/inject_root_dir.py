import subprocess

def get_git_root():
    return subprocess.check_output(['git', 'rev-parse', '--show-toplevel']).decode().strip()

Import("env")
git_root = get_git_root()
env.Append(
    BUILD_FLAGS=[f'-DGIT_ROOT_PATH="\\"{git_root}\\""']
)
