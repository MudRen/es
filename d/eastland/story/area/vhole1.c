
#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��Ѩ");
	set_long(@LONG
����һ��͸��Щ��΢���ߵ�������Ѩ�������洵�����ķ��ڵ�������ȦȦ�γ�
һ��СС������������ַ������������ǰ��ι�ǽ�ڷ����������ݡ�����������
���У������������ڶ����㳰Ц���ҷ��������Ц�����������ĸо�����������ë
���Ȼ�亹ֱ������Ȼ����֪�����ߵ�ʲ�ᶫ������ͷһ������Ȼ��һ�Ѱ׹ǣ���
���ⲻ�Ǹ����Ƶĵط����㻹�ǿ��뿪����Ϊ�
LONG
	);
        set( "exit_suppress", ({
            "down" }) );
	set("exits", ([
            "out" : SAREA"mountain2",
           "east" : SAREA"vhole3",
           "west" : SAREA"vhole2",
           "down" : SAREA"room_h"
        ]) );
        set("pre_exit_func",([
           "out":"can_pass"]));
	reset();
}
void init()
{
    add_action("do_auction","auction");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("��������������ʹ�����޷�������������\n");
    return 1;
}
int can_pass()
{
   object vampire;
   if ( vampire=present("the great vampire",this_object()) ) {
       write(sprintf("%s���˫����ס���ȥ·��\n\n",vampire->query("c_name")));
       return 1;
   }
   return 0;
}
int clean_up()
{
   return 0;
}
