# escape=`
# ^^ set different escape char since Windows uses `\` a lot


#################################################################
#                    * Topas Test DockerFile *                  #
# ------------------------------------------------------------- #
# Authors: David Leek                                           #
# Notes  : Dockerfile for Build 'n Run of Topaz Labs' Test Repo #
#################################################################



FROM mcr.microsoft.com/dotnet/framework/sdk:4.8-windowsservercore-ltsc2019
# Set Specific versioning in the file so you don't have unexpected changes
# e.g. - microsoft/mindowsservercore might get a random version

LABEL maintainer="rhynri@me.com"

# Vars
ENV BUILD_PATH "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools"

# Restore the default Windows shell for correct batch processing.
SHELL ["cmd", "/S", "/C"]

# Install the Build Tools...
# See: https://docs.microsoft.com/en-us/visualstudio/install/build-tools-container?view=vs-2019
RUN `
    # Download the Build Tools bootstrapper.
    curl -SL --output vs_buildtools.exe https://aka.ms/vs/16/release/vs_buildtools.exe `
    `
    # Install Build Tools with the VC Tools workload. 
    # Excluding workloads and components with known issues.
    && (start /w vs_buildtools.exe --quiet --wait --norestart --nocache modify `
        --installPath "%BUILD_PATH%" `
        --add Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
        --add Microsoft.VisualStudio.Component.Windows10SDK.18362 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.10240 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.10586 `
        --remove Microsoft.VisualStudio.Component.Windows10SDK.14393 `
        --remove Microsoft.VisualStudio.Component.Windows81SDK `
        || IF "%ERRORLEVEL%"=="3010" EXIT 0) `
    `
    # Cleanup
    && del /q vs_buildtools.exe

# Set some things in our path - could do this as a one line but it's easier to read.
RUN setx /M PATH "%PATH%%BUILD_PATH%\VC\Tools\MSVC\14.29.30037\bin\Hostx64\x64"
RUN setx /M PATH "%PATH%%BUILD_PATH%\VC\Auxiliary\Build"

RUN mkdir Code `
    && cd Code `
    && curl -SLO --output master.zip https://github.com/TopazLabs/SimpleLib/archive/master.zip `
    && tar -xf master.zip `
    && del /q master.zip

WORKDIR "C:\Code\SimpleLib-master"

# Compile this thing
# If you had a .sln file, you could use a single command `msbuild` here
# or a .spec file or something equivalent to that
# That'd also take care of your dependencies.

# Set VC Vars to x64
RUN vcvarsall.bat x64 `
    && cl /c /EHsc fiblib.cpp `
    && lib fiblib.obj `
    && cl /EHsc main.cpp fiblib.lib

# OPTIONAL: Set an entrypoint that causes the docker to barf out our answer
#ENTRYPOINT ["main", "42"]

ENTRYPOINT ["cmd.exe"]
