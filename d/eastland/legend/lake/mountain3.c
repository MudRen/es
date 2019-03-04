#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "ɽ��" );
    set_long(@C_LONG
����һ��Ƭ������,��ãã��ʹ�㿴�����κζ����� ԶԶ��ȥ,����ԼԼ��
����ͻ���Ʋ��СɽȺ,СɽȺ���ƴ���һ������ɫ��ñ�ӡ������Ա��к�����һ
��⻬���ͱ� ( bluff ) ��
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
           "west"}) );
    set( "exits", ([
       "west":LAKE"mountain2"
    ]) );
    set("c_item_desc",([
        "bluff":"һ��⻬���ͱ�,�ƺ�Ҫ�ܺõļ�����������ȥ��\n"
    ]) );
    reset();
}
init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object player;
    int probability;
    if ( !arg || arg != "bluff" )
       return notify_fail("��Ҫ��ʲ��?\n");
    player=this_player();
    probability=(int)player->query_skill("climbing")/(int)player->query_level();
    if ( probability+random(5)>7 ) {
       tell_object(player,"��ͣҲ��ͣ��һ�����������ͱڡ�\n\n\n\n");
       tell_room(environment(player),sprintf(
          "%sͣҲ��ͣ��һ�����������ͱڡ�\n",player->query("c_name")),player);
       player->move_player(LAKE"mountain4","SNEAK");
       player->receive_damage(10);
       tell_object(player,
          "����!��������µ��ٶ�̫������Աߵ����ٸ�����!\n");
       "/d/magic/magic"->report( this_object(), player );
       return 1;  
    } 
    tell_object(player,
        "��ʹ�����̵������������ͱ�,ȴ��Ϊ�����ļ������û����������������"+
        ",����ɽ����ȥ��!\n");
    tell_room(environment(player),sprintf(
       "%sʹ�����̵������������ͱ�,ȴ��Ϊ�����ļ������û�������,������,����ɽ����ȥ��!�㲻��������Ц��\n",player->query("c_name")),player);
    player->move(LAKE"mountain0","SNEAK");
    player->receive_damage(10);
    "/d/magic/magic"->report( this_object(), player );
    tell_room(environment(player),"��ĳһ������������Ľűߡ���\n",player);
    return 1;    
}
