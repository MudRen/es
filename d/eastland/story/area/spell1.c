#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("����");
	set_long(@LONG
��������һ�����صĽ��أ�����Χ��ʱ����һЩϸ΢���������������������
û���������ԣ��䷢���Ź��Ѽ��������У��㻹���Կ���һЩ���������ĵ��񣬵�
���ģ�����׶�����е�η�壬һ����ĺ�����Ȼ��������˵����������ʩ��
�����ൽ������̽�յ��ˣ�ʮ֮�˾Ŷ����������⣬�����Ƿ���Ϊ������Ĺ�
ϵ�����ԣ��㻹�����ڵ��Ͽ����������ͷ�������뻹�ǿ��뿪����ɣ��׻�˵��
�ã������������в��������ޡ���˵�������������ġ���������ﱻ���˷��֣�
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
              "southup" : SAREA"hole2",
            "northdown" : SAREA"spell2",
                   "su" : SAREA"hole2",
                   "nd" : SAREA"spell2"
        ]) );
	set("light",1);
	reset();
}
void init()
{
    int i;
    object player,*all;
    add_action("do_cant","get");
    add_action("do_cant","auction");
    player=this_player();
    if ( !player->query_temp("can_pass_spell") ) {
       write("\n����ص��������е�������תһ���ѣ��\n\n");
       player->add("hit_points",-30);
       all=all_inventory(player);
       for (i=0;i<sizeof(all);i++) {
          if ( all[i]->query("max_load") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("defense_bonus")||
                    all[i]->query("armor_class") ) all[i]->set("need_drop",1);
          else if ( all[i]->query("weapon_class") ) all[i]->set("need_drop",1);
          else if ( !(all[i]->query("prevent_get")||
                      all[i]->query("prevent_drop")) ) all[i]->set("need_drop",1);
          if ( all[i]->query("need_drop") ) {
             all[i]->move(SAREA"temp_room1");
             if (all[i]->query("name")!="magic cube") all[i]->remove();
          }
       }    
    }
}
int do_cant(string arg)
{
    write("��������Ҫ���⶯������Ȼͷ�е�һ���ʹ�������޷���������ж�����\n");
    return 1;
}