from termcolor import colored

from os import listdir
import subprocess


GrosMathExecPath = "./GroMath"
testsPath = "tests/"

tests = listdir(testsPath)

tn_lens = []
descs = []
descs_lens = []
for test in tests:
    tn_lens.append(len(test))
    with open(testsPath + test, "r") as f:
        descs.append(f.readline()[2:].strip())
    descs_lens.append(len(descs[-1]))

m_lens = max(tn_lens)
m_decs = max(descs_lens)

def pad(s, l):
    assert len(s) <= l, "cant pad, string is too long"
    pl = l - len(s) 
    return s + " " * (pl)

success = 0
for test_id, test in enumerate(tests):
    print(colored(f"[+] Test {test_id + 1} | {pad(test, m_lens)} | {pad(descs[test_id], m_decs)} | ", "blue"), end="")
    comm = [GrosMathExecPath, testsPath + test]
    tr = subprocess.run(comm, capture_output=True)
    out = tr.stderr.decode().strip()
    
    if tr.returncode != 0 or "error" in out.lower():
        print(colored(f"FAILED !! with retcode : {tr.returncode}", "red", attrs=["bold"]))
        for l in out.split("\n")[:2] + ["..."] + out.split("\n")[-5:]:
            print(colored("  ↳ " + l, "red"))
        print(colored("  [!] Command to use to reproduce error : " + " ".join(comm), "red", attrs=["bold"]))
    else:
        success += 1
        print(colored("SUCCESS !!", "green"))
    
print(colored(f"[+] Result : {success} / {len(tests)} successful !", "light_magenta"))