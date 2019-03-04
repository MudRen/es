#include <mudlib.h>
#include <move.h>
inherit ROOM;

void create()
{
	::create();
	set_short( "С͵��������װ����");
	set_long(	@C_LONG_DESCRIPTION
������С͵��������ܴ����ҡ�����ǰһЩ��Ǯ��С͵����ЩǮ\��\������������,
��һЩ��Ҫ��ѵ��С͵��װ���������
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"east" : "/d/thief/hall/thief_shop" ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
	add_action("do_get","get");
}
int do_get(string arg)
{
	object *invs,ob;
	int i;
	
	if ( ! arg ) return 0;
	if ( arg == "all" ) {
		invs = all_inventory(this_object());
		for ( i = sizeof(invs)-1 ; i >=0 ; i -- ) {
		if ( (string)invs[i]->query("owner") != (string)this_player()->query("name") )
//			&& !wizardp(this_player()) )
			continue ;
		if ( invs[i]->move(this_player()) != MOVE_OK )
			continue ;
		invs[i]->delete("owner");			
		}
		tell_object(this_player(),"�����Ķ���ȫ������������\n");
		return 1;
	}
	if ( !ob = present(arg,this_object()) )
		return 0;
	if ( (string)ob->query("owner") != (string)this_player()->query("name") ) {
//		&& !wizardp(this_player()) )
		tell_object(this_player(),"��������㲻�����ߡ�\n");
//		return notify_fail("��������㲻�����ߡ�\n");
		return 1;
	}
	call_other("/cmds/std/_get","cmd_get",arg);
	ob->delete("owner");
	return 1;
}
