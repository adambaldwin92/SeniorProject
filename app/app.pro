TEMPLATE = subdirs

SUBDIRS += src \
    Monitor


CONFIG(debug, debug|release) {
    SUBDIRS += tests
}
