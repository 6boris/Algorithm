
SELECT * FROM b , ( SELECT tid FROM a LIMIT 50000,200) a where a.tid = b.id;

