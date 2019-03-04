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
	set("exits", ([
             "west" : SAREA"vhole1",
        ]) );
	reset();
}
void init()
{
    add_action("do_auction","auction");
    add_action("do_open","open");
    add_action("do_search","search");
}
int do_auction(string arg)
{
    if ( !query("have_vampire") ) return 0;
    write("��������������ʹ�����޷�������������\n");
    return 1;
}
int do_search(string arg)
{
    if ( query("be_open") )
       write("�㷢��һ�ڱ��˴򿪹��Ĺײ�(coffin)��\n");
    else write("�㷢��һ�ڹײ�(coffin)���ƺ����Դ�(open)��\n");
    return 1;
} 
int do_open(string arg)
{
    object ob;
    if (!arg||arg!="coffin") return notify_fail("��Ҫ��ʲ�ᶫ��?\n");
    if ( query("have_vampire") || query("be_open") ) { 
       write("��ڹײ�ҵ�ѱ��˴򿪹��ˡ�\n");
       return 1;
    }
    write("\n\n��Ȼ���ӹײ��бĳ�һ��������\n\n\n");
    ob=new(SMOB"vampire1");
    ob->move(this_object());
    SAREA"vhole1"->set("have_vampire",1);
    SAREA"vhole2"->set("have_vampire",1);
    SAREA"vhole3"->set("have_vampire",1);
    set("be_open",1);
    return 1;
}
int clean_up()
{
    return 0;
}
void reset()
{
    set("be_open",0);
    ::reset();
}