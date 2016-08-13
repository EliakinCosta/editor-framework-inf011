win32 {
qtlzohelp.input        = $${PWD}/QtLzo.qhp
qtlzohelp.output       = $${PWD}/${QMAKE_FILE_BASE}.qch
qtlzohelp.commands     = qhelpgenerator.exe ${QMAKE_FILE_NAME} -o ${QMAKE_FILE_OUT}
QMAKE_EXTRA_COMPILERS += qtlzohelp
}

OTHER_FILES           += $${PWD}/QtLzo.qhp
OTHER_FILES           += $${PWD}/*.html
OTHER_FILES           += $${PWD}/*.css
OTHER_FILES           += $${PWD}/en/*.html
OTHER_FILES           += $${PWD}/cn/*.html
OTHER_FILES           += $${PWD}/tw/*.html
