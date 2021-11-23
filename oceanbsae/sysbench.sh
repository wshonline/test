HOST=172.16.0.59
PORT=2881
USER=root@test
DB=test
THREADS=128
TABLE_SIZE=100000
TABLES=3
TIME=300
REPORT_INTERVAL=10

sysbench --db-ps-mode=disable --mysql-host=$HOST --mysql-port=$PORT \
         --rand-type=uniform --rand-seed=26765 \
         --mysql-user=$USER --mysql-db=$DB \
         --threads=$THREADS \
         --tables=$TABLES --table_size=$TABLE_SIZE \
        #  --warmup-time=30 \
         --time=$TIME --report-interval=$REPORT_INTERVAL \
         subplan $1