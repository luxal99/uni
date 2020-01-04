/**
 * Generated by nik on 04/01/2020
 */
#ifndef __nik_LIBRARY_DB_ENTITY_STRUCT_MUNICIPALITY_H
#define __nik_LIBRARY_DB_ENTITY_STRUCT_MUNICIPALITY_H

#pragma once


#include "db/orm/entity.h"

struct municipality {
	uint id_municipality;
	struct region* region;
	char name[256];
};

typedef struct municipality MUNICIPALITY;

uint municipality_insert(MYSQL* conn, MUNICIPALITY* municipalityT);

SQL_RESULT* municipality_execute_find(MYSQL* conn, char const* query, MYSQL_BIND* params, uint param_count);

MUNICIPALITY* municipality_find_by_id(MYSQL* conn, uint id);

int municipality_update(MYSQL* conn, MUNICIPALITY* municipalityT);

int municipality_execute(MYSQL* conn, char const* query, MYSQL_BIND* params, uint param_count);

int municipality_delete(MYSQL* conn, MUNICIPALITY* municipalityT);

SQL_RESULT* municipality_find_all(MYSQL* conn);

void municipality_free(MUNICIPALITY** ptr);

#endif
