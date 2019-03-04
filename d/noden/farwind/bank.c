//#pragma save_binary

// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include "farwind.h"
#include <money.h>
#include <move.h>

inherit "/std/bank";
inherit ROOM;

void create()
{
	room::create();
	reset();
	set_short( "����");
	set_long(@C_LONG
��ӭ����Զ��������Ϊ�������С���������ֻҪ���� 25 ���ҾͿ���
��(open)һ����ͷ�����������ṩ�ķ���������Ա�����һ�Ŵ��𿨣���
���������ſ����������صķ��д��(deposit)�����(withdraw)�� ����
��������һ��¥��ͨ����¥��Ǯ�Ҷһ����ġ�
C_LONG
	);
	set("light", 1);
	set("exits", ([ 
		"west" : FARWIND"nmain",
		"up" : FARWIND"exchange"
	]) );
	set("objects", ([ 
		"janitor" : FARWIND"monster/taxman" ]) );
	reset();
}
