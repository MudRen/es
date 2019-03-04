// The Netdead Room, clooect all users who are net-dead, 
// will clean up every 30 mins
// created by Kyoko, 5-11-1994.

#include <mudlib.h>

inherit ROOM;

string *where = ({ "/d/noden/12,3.noden","/d/noden/17,8.noden",
		"/d/noden/2,15.noden","/d/eastland/9,9.east",
		"/d/eastland/7,17.east","/d/deathland/city/c5"
		}) ;
void create()
{
	::create();
	set_short("ʱ��ķ�϶" );
	set_long(
		"���������ʱ��ķ�϶����Ŀ�����ǲ�����Ŀ���߲ʹ�â��\n"
		"�ռ��д�������������(door)����˵����ͨ��������ء�\n"
	);
	set("light", 1);
    set("c_item_desc",(["door":
	"����һЩ�����߲ʹ�â���ţ��������һ�Ƚ�ȥ(enter)������\n"
     ]));
}

void init() 
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	string move_to;
	int hp;
        if( !arg || arg!="door" )
            return notify_fail("�������\n" );
	write("������һ�����߽�ȥ��ͻȻ������һ���ȿ�....\n" );
	tell_room( this_object(),
            this_player()->query("c_name") + "�߽�һ�������ʧ��...\n",
                this_player() );
	move_to = where[random(sizeof(where))];
	this_player()->move_player( move_to, "SNEAK" );
	write("��������һ�����ڵ��ϣ�ˤ��ƨ��ʹ���� ...\n");
	this_player()->add("hit_points",-(int)this_player()->query("hit_points")/10);
	tell_object(this_player(),sprintf("( ��%s )\n",(string)"/adm/daemons/statsd"->status_string(this_player())));
	tell_room( move_to ,
            this_player()->query("c_name") + "�ݡ�����һ������������ˤ���Ľų��졣\n",
                this_player() );
        return 1;
}

int receive_object(object arg)
{
	string msg ;
	object* all_inv;
	if(living(arg)) return 1 ;    
	if (base_name(arg)=="/std/statue") return 1;
	tell_room(environment(this_player()),
              arg->query("c_name")+"��һ���ڶ����ɣ�˲�����ʧ�ˡ�\n");
	all_inv=all_inventory(arg);
	all_inv->remove();
	arg->remove();
	return 0;
}
