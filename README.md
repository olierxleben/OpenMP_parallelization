pva-praktikum
=============

Praktikum Verteile und Parallele Algorithmen

Wichtiges/Caveats
-----------------

* Beim Überladen des ()-Operators bei Funktionsobjekten muss **auf jeden Fall** der
  Modifier `const` angegeben werden:

      class Test {
        public:
          void operator() (blocked_range<int>& range) const {
            // ...
          }
      }
