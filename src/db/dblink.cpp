#include "db/dblink.h"
#include "db/dbdatabase.h"
#include "db/dbtable.h"

sad::db::Link::Link() 
: m_cached_object(NULL),
m_minor_id(0),
m_major_id(0),
m_link_by_name(false),
m_link_by_major_id(false),
m_table(NULL),
m_database(NULL)
{

}

sad::db::Link::~Link()
{

}

sad::db::Object* sad::db::Link::get()
{
    if (m_cached_object == NULL)
    {
        if (m_link_by_major_id)
        {
            if (m_database == NULL)
            {
                if (m_table != NULL)
                {
                    m_database = m_table->database();
                }
            }
            if (m_database)
            {
                return m_database->queryByMajorId(m_major_id);
            }
            return NULL;
        }

        sad::db::Table* table = this->table();
        if (table)
        {            
            if (m_link_by_name)
            {
                sad::Vector<sad::db::Object *> o = table->queryByName(m_name);
                if (o.size())
                {
                    m_cached_object = o[0];
                }
            }
            else
            {
                m_cached_object = table->queryByMinorId(m_minor_id);
            }
        }
    }
    return m_cached_object;
}

void sad::db::Link::setDatabase(sad::db::Database * db)
{
    m_database = db;
    m_cached_object = NULL;
}

sad::db::Database* sad::db::Link::database() const
{
    return m_database;
}

void sad::db::Link::setTableName(const sad::String & t)
{
    m_table_name = t;
    m_table = NULL;
    m_cached_object = NULL;
}

const sad::String& sad::db::Link::tableName() const
{
    return m_table_name;
}

void sad::db::Link::setTable(sad::db::Table * t)
{
    m_table_name.clear();
    m_table = t;
    m_cached_object = NULL;
}

sad::db::Table* sad::db::Link::table() const
{
    if (m_table == NULL && m_table_name.size() != 0 && m_database != NULL)
    {
        const_cast<sad::db::Link*>(this)->m_table = m_database->table(m_table_name);
    }
    return m_table;
}


void sad::db::Link::setMajorId(unsigned long long major_id)
{
    m_cached_object = NULL;
    m_link_by_name = false;
    m_link_by_major_id = true;
    m_name.clear();
    m_major_id = major_id;
}


unsigned long long sad::db::Link::majorId() const
{
    unsigned long long result = 0;
    if (m_link_by_major_id)
    {
        result = m_major_id;
    }
    else
    {
        sad::db::Object* o = const_cast<sad::db::Link*>(this)->get();
        if (o)
        {
            result = o->MajorId;
        }
    }
    return result;
}

void sad::db::Link::setMinorId(unsigned long long minor_id)
{
    m_cached_object = NULL;
    m_link_by_name = false;
    m_link_by_major_id = false;
    m_name.clear();
    m_minor_id = minor_id;
}

unsigned long long sad::db::Link::minorId() const
{
    unsigned long long result = 0;
    if (m_link_by_name == false && m_link_by_major_id == false)
    {
        result = m_minor_id;
    }
    else
    {
        sad::db::Object* o = const_cast<sad::db::Link*>(this)->get();
        if (o)
        {
            result = o->MinorId;
        }
    }
    return result;
}

void sad::db::Link::setName(const sad::String & name)
{
    m_cached_object = NULL;
    m_link_by_name = true;
    m_link_by_major_id = false;
    m_name = name;
    m_minor_id = 0;
}

const sad::String & sad::db::Link::name() const
{
    return m_name;
}

void sad::db::Link::setObject(sad::db::Object* o)
{
    m_cached_object = o;
}
