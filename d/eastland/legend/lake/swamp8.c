#include "/d/eastland/legend/legend.h"

inherit ROOM;
inherit LAKE"in_swamp";
int be_search,be_dig;

void create()
{
        ::create();
    set_short("����");
        set_long( 
@LONG
������������⣬���߽�����Σ�յ�����أ����ܶ�����������������������
��ֵ��ǣ����ﲻ����������س�����ʽ�������˵ľ��͹��Ҳû������ġ���
���෴�ģ����ﵽ�����Ǿ���������޵Ĳк�����Ȼ���Ѿ�վ�������һ��ʱ�䣬
��ȴû���κ�һֻ����׷������������Ѱ�����ֵĿ�����������һ��Ũ���Ѫ�ȶ�
������ɶ�����������̱ǣ������ţ�����ÿ��һ��ʱ��ʹ���һ���Х��������
��ţ�裬��ȴԶ�������������룬һ���Ǹ��ֲ��Ĺ��
LONG
    );
    set( "exit_suppress", ({
           "east","north","west","south","down"}) );
    set("exits",([
            "east":LAKE"swamp7",
           "north":LAKE"swamp7",
            "west":LAKE"swamp7",
           "south":LAKE"swamp8",
            "down":LAKE"swamp_d1"
    ]) );
    be_search=0;
    be_dig=0;
    reset();
}
void init()
{ 
    ::init();
    add_action("do_search","search");
    add_action("do_shake","shake");
}
int do_search(string arg)
{
    if ( be_search ) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    tell_object(this_player(),
       "���ҵ�һ�á���������(tree)��ҡҡ(shake)��˵��������ʲ�ᶫ����������\n");
    be_search=1;       
    set("c_item_desc",([
          "tree":
"       ����һ�ù������õ�������������״�е����������Ҷ����Щ\n"
"       ���������飬����������ԶԳƵ�������֦���ɣ������ɲ���\n"
"       Ϊ����ԶԶ��ȥ���е������ǵ�β�͡�\n"
    ]) );                     
    return 1;
}
int do_shake(string arg)
{ 
    object fruit;
    if (!arg || arg!="tree") return 0;
    if (!be_search) return 0;
    if (be_dig) return 0;
    if ( (int)this_player()->query_temp("mobs") < 20 ) return 0;
    be_dig=1;
    this_player()->delete_temp("mobs");
    tell_object(this_player(),
        "������ҡ���������������������Ҷ����һ�ź�ɫ�Ĺ�ʵ��\n");
    fruit=new(LITEM"fruit");
    fruit->move(this_object());
    delete("c_item_desc/tree");
    call_out("do_recover",300);
    return 1;
}
void do_recover()
{
    be_search=0;
    be_dig=0;
}
void reset()
{
    be_search=0;
    be_dig=0;
    delete("c_item_desc/tree");
    ::reset();
 }