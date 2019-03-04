#include "takeda.h"

inherit ROOM;

void create()
{
	object me;
	me = this_player();
	::create();
	set_short( "����ƽ̨" );
	set_long(
	"��������һ��СС��ƽ̨��ԭ���ƺ����������ͣ����ֻ�ģ���������Ϊ\n"
	"ʯ�ٴ������Խ��Խ������ȥ�����ˣ����ﷴ����ɵ�����˴������ֵ�\n"
	"�õط���������д��������Ļ�����������ڴ�����������\n");
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
        "south" : TROOM"village2"]));
                        
        set( "objects" ,([
        "fisher" : TMONSTER"fisher"]));
        reset();
}
void init()
{
   add_action("do_fish","fish");
   add_action("do_pull","pull");
}
int do_fish()
{
   if ( !(int)this_player()->query_temp("can_fish")==1)  { 
   write(
   "\n���ǽ�̫����??\n");  
    return 1; 
    }
   if ( present("fish rod",this_player()) )
     {
      write(
      "\n��ѵ���׼���ã����˸������λ�����£���ʼ���ֵĵ���...\n\n");
     
      tell_room(this_object(),
      "�㿴��"+this_player()->query( "c_name")+"׼���õ��ͣ���ʼ���ֵĵ��㡣\n",this_player());
   if (present("fisher")) 
     {
      write(
      "\n�Աߵĵ����˰�ͷ���˹�����˵��: ��Ҳ��������İɣ�������Ҫ�ܴ��\n"
      "���ģ���Ȼ�ǲ����ܵ��ĵ���ġ�\n\n");
     
     
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",30,this_player());
     return 1;
     }
  else 
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",50,this_player());
     return 1;
    }
  else  {
    write(
    "������ʲ�ᶫ��������?\n");
    return 1;    
        }
}
int recover(object me)
  { 
   if (!present(me)) return 1;
   write(
   "\n����������е����ĵ�ʱ����ĸ���ͻȻһ�����㿴�����͵ĸ���\n"
   "��������Ļ��ͣ�����һ��ǿ�ҵ�������˳����ĵ��ʹ�������Ͽ�\n"
   "������֪�ò��ý���������������?\n\n");
   tell_room(me,
      "\n������������ĵ�ʱ���㿴��"+this_player()->query( "c_name")+"ͻȻ����\n"
      "\n������������!\n\n"
      ,this_player());
               
   this_player()->set_temp("fish_quest/fish",2);
   return 1;
   }   
 int do_pull(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "rod" )
 return notify_fail(
 "����ʲ��?\n" );
 if ((int)this_player()->query_temp("fish_quest/fish")==2 )  {
 if ( !(int)this_player()->query_temp("can_fish")==1) {
 write("��װ����...\n");
 return 1;
 }
 if (random(6)>4) {
 write(
 "\n�����һ������: ����ʲ�ᶼû��������\n\n");
 tell_room(me,
 "\n"+this_player()->query("c_name")+"����һ�����ͣ�����ʲ�ᶼû����..\n\n"
 ,this_player());
 return 1;
 }
    switch (n=random(10) ){
    case 0: ob = new(TMONSTER"fish1"); break; 
    case 1: ob = new(TMONSTER"fish2"); break;
    case 2: ob = new(TMONSTER"fish3"); break;
    case 3: ob = new(TMONSTER"fish4"); break;
    case 4: ob = new(TMONSTER"fish5"); break;
    case 5: ob = new(TMONSTER"fish6"); break;
    case 6: ob = new(TMONSTER"fish7"); break;
    case 7: ob = new(TMONSTER"fish8"); break;
    case 8: ob = new(TMONSTER"fish9"); break;
    case 9: ob = new(TMONSTER"fish10"); break;            
                }
 ob->move( environment(this_player()) );
         
 write(
  "\n�����һ������: һ������˳�Ʒɵ����ϣ���е�һ����������㣬����\n"
  "����Ȼ��ͣ������....\n");
   tell_room(me,
   "\n"+this_player()->query("c_name")+"����һ�����ͣ��������һ�����㡣\n\n"
   ,this_player());
   ob->kill_ob(this_player());
   this_player()->kill_ob(ob);
   this_player()->delete_temp("can_fish");
   return 1;
 }
 write(
 "\n���ĵ㣬�ٵȵȰɡ�\n");
 return 1;
}