#!/usr/bin/env bash
REMOTE_HOST=home-dev.local
REMOTE_SSH_PORT=22
rsync -avPe "ssh -p $REMOTE_SSH_PORT" ./* root@$REMOTE_HOST:/root/audio-player/
