import os, requests, sys, json

repo = os.environ["REPO"]
pr_number = os.environ["PR_NUMBER"]
api_url = os.environ["AI_SERVICE_URL"].rstrip("/") + "/generate-tests"

print("API URL:", api_url)
with open("pr_diff.txt") as f:
    diff = f.read()

try:
    r = requests.post(
        api_url,
        json={"diff": diff, "language": "python", "framework": "pytest"},
        timeout=60,
    )
except Exception as e:
    print("Request failed:", e)
    sys.exit(1)

print("AI Status Code:", r.status_code)
print("AI Raw Output:", r.text[:5000])

if r.status_code != 200:
    sys.exit(1)

suggestions = r.json().get("suggestions_markdown", "")

comment_url = f"https://api.github.com/repos/{repo}/issues/{pr_number}/comments"

resp = requests.post(
    comment_url,
    headers={
        "Authorization": f"Bearer {os.environ['GITHUB_TOKEN']}",
        "Accept": "application/vnd.github+json",
    },
    json={"body": suggestions},
)

print("Comment Status:", resp.status_code)
print("Comment Response:", resp.text)

if resp.status_code >= 300:
    sys.exit(1)
