#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "���" );
	set_long(
	"���߽���һ����ͨ�ķ��ӣ���ȻխС����ȴ��ɨ��һ����Ⱦ��ǽ��\n"
	"����һ����ˮ��(cistern)���������ʢ������ˮ����֪�Ǹ����õ�?\n"
	  );
        set("c_item_desc",(["cistern":
"���ߵ�ˮ�ױߣ���ϸ�۲����ˮ�ף��㷢��ˮ��������\��������С�㣬����\n"
"����������ȥ������ܿ��ֵ����ӡ���ͻȻ��һ�����ö��������ǵĳ嶯��\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village1"
        ]) );
        	set( "pre_exit_func",([
	        "east" :"check_feed"
	        ]));
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "cistern")
    return notify_fail(
    "����Ҫ��ȥ�Ƕ�?\n");
    write (
    "���ߵ�ˮ�ױߣ�����ǿ�İ��Լ�����ˮ�ף����˼���ˮ�ᣬ�㿪ʼ����\n"
    "�»�����\n");
    tell_room(this_object(),
    "�㿴��"+this_player()->query("c_cap_name")+ "һͷ���ˮ���\n" ,
    this_player());
    this_player()->move_player("/d/eastland/liang_shan/lake/cistern","SNEAK");
   return 1;
}
int check_feed()
{    
object fisher;
if ( !(int)this_player()->query_temp("feed_fish")==1 || present("fisher") ) return 0;
write(
"ͻȻ�䣬һ���˼���ææ�ĳ��˽�����������ײ���������ͣ����׼����������..\n"
"���ðʧ��æ��Ц��: �Բ�����ֻ�Ǹϻ������㣬������������������Ѿ����˰ɡ�\n"
"����лл����...\n");
fisher =new("/d/eastland/liang_shan/monster/fisher1");
fisher->move(TROOM"room2");
this_player()->delete_temp("feed_fish");
return 1;
}
    