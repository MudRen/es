#include <mudlib.h>
#include "/d/eastland/legend/legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "ɽ��" );
    set_long(@C_LONG
�㷭���ղ������ͱ�(bluff)֮��������ɽ����һ�ߡ� ������������һ��ɽ��
��ɽ·�ϣ�ɽ·��᫲�ƽ�����ϳ���Щϡϡ�����Ұ�ݣ��Ա���һ�Ŵ����������
��Ұ�ܺã��㸩����ȥ���Կ���һ������
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
      "follow-bluff"}) );
    set("c_item_desc",([
      "�ͱ�":"@@do_look",
      "bluff":"@@do_look",
      "�⻬���ͱ�":"@@do_look"
    ]) );               
    set( "exits", ([
      "follow-bluff":LAKE"mountain3",
     "west":LAKE"mountain5"
    ]) );
    reset();
}
void init()
{
   add_action("do_search","search");
}
int do_search(string arg)
{
   tell_object(this_player(),"���ҵ���һ��⻬���ͱ�( bluff )\n"); return 1;
}
string do_look()
{
    return "һ��ܶ����ͱڣ������������ ( follow-bluff ) ��ɽ����һ�ߡ�\n";
}