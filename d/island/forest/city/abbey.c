#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("��ľ����");
    set_long(@LONG
���ﳤ���÷ǳ�ï�ܵĴ���(tree)���Ա߻��������磬��ͷд������ľ���硻
�ĸ��֣�������Χ��ɨ��ʮ��Ǭ�����������һ��ׯ�����µ�����£����������ԣ�
�ѵ�������Ǽ������������ػ����ǵĵط���
LONG
       );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway2"]) );
    set("item_desc",([
        "tree":@ALONG
�ۡ���������ô����������ƺ�Ҳ���������ˣ�ֻ�ǿ������ƺ��ȳ����ǿø�
������ʷ��������������ͻȻ���������Ѳ�����Ҳ��һλ�ػ���Ļ��������
�ǣ�����������һλ�أ��š�����������(abbey)��Ӧ���ܻ�ý��
ALONG
     ,"abbey":@BLONG
����������ħ�崫ͳ���������������磬��Ȼ�Ʋ��ϸ����ûʣ�����ɢ����
����ʥ�����ֵ���Ϣ��ȴʹ�˲������κβ����ľٶ����ţ������룺Ӧ�ÿ��Խ�ȥ
(enter)�ΰ�һ���ɣ�
BLONG
          ]) );
    reset();
}

void init()
{ 
   add_action("do_enter","enter");
   add_action("do_pray","pray");
}


int do_enter(string str)
{
    if( !str || str != "abbey")
    return notify_fail("��Ҫ�����\n");
    write("\n\n..........��˫�ֺ�ʮ������򯾴�����鲽������..........\n\n\n");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"����򯾴�����黺���Ĳ������磡\n"
        ,this_player() );
    this_player()->move_player(CITY"abbey1","SNEAK");
    tell_room( environment(this_player()),
        this_player()->query("c_name")+"����򯾴�����黺�������˽�����\n"
        ,this_player() );
    return 1;
}       
         
int do_pray()
{
    write(@ALONG
ͻȻ����Ҷ���һ�����Ĺ��ߣ��������ǰ���γ�һƬ��Ļ����һ������ػ���
�����Ȼ����Ĵӹ�Ļ��Ʈ�˳�����
�����װ������ߣ�����Ŀǰ������һ����ƽ٣�Ҳ���ػ���֮һ�����ʿ�Ҫ�ľ����е�
�����ˣ�Ϊ��ħ��������봫�У����������������(seed)������԰���������ڻ�԰��
�����������������Խ�ת����������ȥ��������˵�ľ�ֻ��������ˣ����ߣ�һ�ж���
������.........
�����ػ����������òʹ����������֮�У�֮����������ȫ���ǵ���.......--|:
ALONG
           );
    tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "����վ����ǰ��ͻȻ���ˮֱ�������Ǹ����ļһ��Ȼ�����������...\n"
      ,this_player() );
    return 1;
}         
