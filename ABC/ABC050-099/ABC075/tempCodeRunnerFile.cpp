for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int cnt = 0;
            for(int k = 0; k < 8; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                if(s[ny][nx] == '#') cnt++;
            }
            ans[i][j] = cnt;
        }
    }