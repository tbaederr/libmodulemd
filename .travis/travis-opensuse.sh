#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
pushd $SCRIPT_DIR

source $SCRIPT_DIR/travis-common.inc

set -e
set -x

JOB_NAME=${TRAVIS_JOB_NAME:-openSUSE tumbleweed}

arr=($JOB_NAME)
release=${arr[1]:-tumbleweed}

mmd_run_docker_tests \
    os=opensuse \
    release=$release \
    repository=registry.opensuse.org \
    image=opensuse/$release

