//header file for the table functions
//Aidan Alme and Bob Dong
//aalme2@jhu.edu / bdong9@jh.edu
#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <string>
#include <pthread.h>

class Table {
private:
  std::string m_name;
  pthread_mutex_t mutex;
  std::map<std::string, std::string> table;
  std::map<std::string, std::string> tentative_table;
  // copy constructor and assignment operator are prohibited
  Table( const Table & );
  Table &operator=( const Table & );

public:
  Table( const std::string &name );
  ~Table();

  std::string get_name() const { return m_name; }

  void lock();
  void unlock();
  bool trylock();

  // Note: these functions should only be called while the
  // table's lock is held!
  void set( const std::string &key, const std::string &value );
  bool has_key( const std::string &key );
  std::string get( const std::string &key );
  void commit_changes();
  void rollback_changes();
};

#endif // TABLE_H
