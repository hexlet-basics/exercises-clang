#!/bin/bash

set -o pipefail
tcc -run test.c | greenest
