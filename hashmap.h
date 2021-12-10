

#ifndef HASHMAP_
#define HASHMAP_

template <class K, class V>
struct Bucket {

   K key;
   V value;

   Bucket(K key, V value) {
      this->key = &key;
      this->value = &value;
   }
};

template <class K, class V>
class HashMap {

private:

   // size of table & number of potential entries
   int num_buckets;

   // takes in key and returns hash value
   int hashify(K);

   // array holding all entries
   Bucket<K, V>** table;

public:

   // Constructor for HashMap
   HashMap();

   // Destructor for HashMap
   ~HashMap();

   //V& operator[](K);

   // adds a value to the hashmap
   bool add(K, V);

   // retrieves a value from the hashmap
   V get(K);

   // displays all entries in the hashmap
   void display();
};

// templates have funny rules so runtime information is here

template <typename K, typename V>
HashMap <K, V>::HashMap() {

   num_buckets = 97;
   table = new Bucket<K, V>[num_buckets];

   // sets whole array to nullptr
   for (int i = 0; i < num_buckets; i++) {
      table[i] = nullptr;
   }
}

template <typename K, typename V>
HashMap <K, V>::~HashMap() {

   for (int i = 0; i < num_buckets; i++) {

      Bucket<K, V>* entry = table[i];

      delete entry;

      //table[i] = nullptr;
   }

   delete[] table;
}

template <typename K, typename V>
int HashMap <K, V>::hashify(K key) {

   return std::hash<int>() (key) % num_buckets;
}
/*
template <typename K, typename V>
V& HashMap <K, V>::operator[](K) {
   return *table[hashify(K)];
}
*/
template <typename K, typename V>
bool HashMap <K, V>::add(K key, V val) {

   int i = hashify(key);
   //bool set = false;

   while (i > -1 && i < num_buckets) {
      
      if (table[i] == nullptr) {
         table[i] = new Bucket<K, V>(key, val);
         return true;
      }
      // if duplicate value return false
      else if (table[i]->key == key) {
         return false;
      }
      else {
         i++;
      }
   }
}

template <typename K, typename V>
V HashMap <K, V>::get(K key) {

   int i = hashify(key);

   if (table[i]->key == key) {
      return table[i]->value;
   }
   else {
      //return nullptr;
   }
}

template <typename K, typename V>
void HashMap <K, V>::display() {
   cout << "[";
   for (int i = 0; i < num_buckets; i++) {
      if (table[i]->value) {
         cout << table[i]->value << ", ";
      } 
      else {
         cout << "0, ";
      }
   }
   cout << "]";
}

#endif
