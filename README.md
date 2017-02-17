# ee160
A repo for group projects and homework

# Download guide

Hey guys. We are going to use this folder to share our code for the rest of the labs and homework assignments. Using git may be a little confusing at first but it is worth getting used to. Here are instructions on how to get set up.

1. Create a GitHub account, and then email it to be so I can give you permission to push to this repository.

2. Go to the webpage that contains the repo on GitHub. Click on the green "Clone or download" button. Check that above the link it says "Clone with HTTPS". Copy the link.

3. cd in to your ee160 folder. Type `git clone ` and then paste the link into the terminal. You can paste in terminal with Ctrl-LShift-V.

4. Rename the folder to ee160-shared. `mv ee160/ ee160-shared/`.

5. cd into the downloaded folder. type `git config --global push.default simple`

# Using git

There are only a few commands you need to remember. The workflow for git is the following:
Pull, Add, Commit, Push.
First, pull any changes from remote.
Second, do any work you need to.
Third, Add your work to the git project.
Fourth, commit your work.
Fifth, push your work to the remote for others to pull.


Here are some commands you will be using.

Pull changes:
`git pull`

Check status of work:
`git status`

Add changes:
`git add <name of file changed>`

Commit changes:
`git commit -m "<Message to explain what you changed>"`

Push:
`git push`


# Push without entering password

type:
`git config --global credential.helper cache`
