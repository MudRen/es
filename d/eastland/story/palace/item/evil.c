#include <mudlib.h>
inherit OBJECT;
int duration,times;
void trigger();
void reset_duration();
void create()
{
        set_name("evil damn","а�鸽��");
        set_short("а�鸽��");
        set_long(@LONG
һ����������а��Ķ��飬������������Թ�޵������ݺݵص����㣡        
LONG
        );
        set("prevent_drop",1);
        set("prevent_get",1);
        set("prevent_insert",1);
}
void reset_duration()
{
      duration=10;
      times+=1;
}
void init()
{
   add_action("do_block","demand");
   add_action("do_block","backstab");
   add_action("do_block","wield");
   add_action("do_block","unwield");
   add_action("do_block","cast");
   add_action("do_block","enhant");
   add_action("do_block","eungon");
   add_action("do_block","embattle");
   add_action("do_block","fist");
   add_action("do_block","acupunct");
   add_action("do_quit","quit");
}
void do_quit(string arg)
{
   write("\nа��ŭ�����ߣ��� Quit ����������� ? \n\n");
   environment(this_object())->set("hit_points",1);
}
int do_block(string arg)
{
   write("\n�㱻а�鸽���޷����������� !\n\n");
   return 1; 
}
int damage(object victim)
{
   int dam;
   switch( times ) {
   case 1:dam=victim->query("max_hp")/20;
          break;
   case 2:dam=victim->query("max_hp")/15;
          break;
   case 3:dam=victim->query("max_hp")/10;
          break;
   case 4:dam=victim->query("max_hp")/8;
          break;
   default : dam=victim->query("max_hp")/6;
          break;
   }
   return dam;
}
void effect_damn()
{
   object statue,player;
   player=environment(this_object());
   if ( duration==0 ) {
      tell_object(player,"\n�����������ϵ�а�黳�������Թ����ʧ��!!\n\n");
      remove();
   }
   else {
      duration--;   
      if ( ( player->query("inactive") ) == 1 ) {
   //   if ( !interactive(player) ) {
         if ( statue=player->query("statue") )
            statue->remove();
         player->set("hit_points",1);
         player->remove();
         remove();
         return ;
      }
      player->receive_damage(damage(player));
      tell_object(player,"�����������ϵ�а���𽥵ؿ�ʳ������� ...\n");
      call_out("effect_damn",4);
   }
}
void trigger()
{
   reset_duration();
   effect_damn();
}
