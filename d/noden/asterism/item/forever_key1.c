

#include <mudlib.h>

inherit OBJECT;
// inherit DAEMON;

void create()
{
	set_name( "key of forever", "����֮Կ" );
	add( "id", ({ "key" }) );
   set_short( "����֮Կ" );
	set_long(
		"һ����ҫ�������â�������κ���ʯԿ�ס�\n"
	);
	set( "unit", "��" );
	set( "to_lock", "ASTERISM_2" );
	set( "weight", 3 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
   add_action("do_unlock","unlock") ;
}

int do_unlock(string str)
{
	mapping doors;
	mixed *all_keys;
	object key, env;
	string *tmp, dir, key_name;
	int i, chinese_mode;

	chinese_mode = can_read_chinese();

	if( !str || str == "")
           return notify_fail(
                     "��Ҫ��ʲ������\n" );

	env = environment(this_player());

	if(!env) return 0;

	//	Get the door mapping from the environment.
	doors = env->query("doors");

	if(!doors)
           return notify_fail(
                   "����û���������š�\n" );

	dir = env->query_door(str);
	if( !dir )
           return notify_fail(
                   "��Ҫ��ʲ������\n" );

	all_keys = filter_array( all_inventory(this_player()), "find_keys", this_object());
	if( !all_keys || sizeof(all_keys) < 1 )
           return notify_fail(
                   "������û���κ�Կ�ס�\n" );

	//	Get array of existing door directions.
	tmp = keys( doors );

	//  Check to see if the user can actually see.
	if(!this_player()->query("vision")) {
           write(
                   "���ںڰ��������ŵ�Կ�׿�....\n" );
		dir = tmp[ random(sizeof(tmp)) ];
	}

	//	Check to see if the door actually has a unlock.
	if( !doors[dir]["lock"] || doors[dir]["lock"] == "none" )
           return notify_fail(
                   "�������沢û�з����κ�Կ�׿ס�\n" );

	//	Now check and see if the door is actually locked.
	if(doors[dir]["status"] == "open" || doors[dir]["status"] == "closed")
           return notify_fail(
                   doors[dir]["c_name"] + "��û��������\n" );

	//	See if the key fits, or is a skeleton key.
	for( i=0; i<sizeof(all_keys); i++ )
		if( (string)all_keys[i]->query("to_lock") == doors[dir]["lock"] ) {
			key = all_keys[i];
			break;
		}

	if( !key )
           return notify_fail(
                   "���Թ��������е�Կ�ף�����Ȼ�򲻿���\n" );

	//	Okay...unlock the door, and update its linked mirror lock.
	env->set_status(dir, "closed");
	env->update_link(dir);

   write(
     "����" + key->query("c_short") + "��" + doors[dir]["c_name"] + "�ϵ����򿪡�\n" );
   tell_room( env,
		(string)this_player()->query("c_cap_name") + "��Կ�״�" + doors[dir]["c_name"] + "�ϵ�����\n",
		this_player() );

        if ( doors[dir]["lock"]=="ASTERISM_2" && (string)key->query("to_lock")=="ASTERISM_2" )
           {
              write(
                     "�������֮Կ����ʧȥ��â.������ʧ�����ˡ�\n" );

              tell_room( env,
                 (string)this_player()->query("c_cap_name")+
                              "������֮Կ����ʧȥ��â.������ʧ�����ˡ�\n" ,
                this_player() ) ;
              key->remove() ;
            }

	return 1;
}

protected int find_keys(object obj) {  return (int)obj->id("key");  }
