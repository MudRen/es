#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ԭ");
	set_long(@LONG
��������һ���տ��Ĳ�ԭ�������ϱ��ǲ�ԭ�����죬�����Ǵ���Ⱥ���ڲ�ԭ��
������ЩСС�İ�������������ɫ���ʡ�������һ�ţ�����������Ũ������ζ����
��֮�⣬һȺҰ�����������յش����ڻ��Լ䣬���ز������ۡ��㶫����һ��ǧ
��ߵ�ɽ�ڣ�����ͻ�������СС���ҿ�������Ӱ�һ���ľ�Ȼ��������˵��
ɽ���Ǿ���ʯͷ�ѻ������ģ��ҿ��������ѷ죬�������Է������С���������
��һֻ�ŵ����������������������죬������Լ��˵���( climb )��
LONG
	);
	set("light",1);
	set("exits", ([ 
            "west" : SAREA"plain3",
           "south" : SAREA"plain2",
        ]) );
	reset();
}
void init()
{
   add_action("do_climb", "climb" );
}
int do_climb()
{    
   int climb_skill;
   object player;
   string name;
   player=this_player();
   name=player->query("c_name");
   climb_skill = (int)player->query_skill("climbing");
   if( random(climb_skill) < 20 ) {
      write("\n\n��Ȼ��ʹ����ȫ�������ȴһ����С�Ĳȴ�ط�������ȥ��\n\n");
      tell_room(this_object(),sprintf(
         "%s����ʯ���������������ʧ�ܵ���������\n",name),player);
      player->receive_damage(20);
      return 1;
   }
   write("\n��ͷҲ������Ҳ������ר��������ȥ����\n\n\n\n\n\n");
   player->move_player(SAREA"mountain1",({
        "%s������������ȥ��\n",
        "%s����������������\n"}),"");
   return 1;                   
}