#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "����" );
	set_long(
	"������ɽ���ڵĴ��ڳ������ṩ��ѵ�ʳ�����(pot)��������ʳ�ð\n"
	"������İ��̣����ǹ���ֵ�ζ��ȴ���˲��ҹ�ά������ɢ��������ʳ���\n"
	"���������������������ʮ�ֲ�ע��������\n"
	);
	set( "light",1 );
        set( "exits", ([
                "north"  : TROOM"path4",    
        ]) );
        set( "c_item_desc", ([
                "pot" : @POT
��̽ͷ�����п�ȥ����һ��𤲻��ߴ�Ķ�����֪����ʲ�ᣬ������������Ż��
����ǰ��ϸһ�����㷢��һ������ֵ��£������ﶼ��Щ����ܲ��ͻƶ�����
���ϵĶ������ѵ���ɽ�����˶�����?
POT
]));              
        set( "objects",([
             "cooker" : TMONSTER"fat"
             ]));
        reset();
}
void init()
{
   object obj;

   add_action("do_sweep","sweep");
   add_action("do_consider","consider");
   add_action("do_suggest","suggest");
   if ((int)this_player()->query_temp("fat_quest/fish")==2 && present("cooker")) {
   obj = new("/d/noden/asterism/item/tea01");
   write(
   "�ʶ�˵��: �������ˣ���˵�ߵ��˱���ݲ����.......\n");
   this_player()->set_temp("fat_quest/fish",3);
   write(
   "�ղ����ȥ��ʱ����˳ͷ������������һЩ��Ϻ���Ҿ���������һЩ����\n"
   "��Ҫ��Ҫ���Կ�................\n\n"
   "����������̨����������ʳ��������У���������.........\n\n"
   "˵ʵ����ζ��ʵ�ڲ��Ǻܺã������ʶ�����⿼���(skill)�д���ǿ��\n");
   obj->move(this_object());
}
}
int do_sweep()
{
   if ( present("broom",this_player()) )
     {
      write(
      "��һ�ߺ���Сë¿��һ�߰ѳ�����ɨ��ǬǬ����....\n\n");
     
      tell_room(this_object(),
      "�㿴��"+this_player()->query( "c_name")+"����ɨ�ѣ�Ŭ����������������\n",this_player());
   if (present("cooker")) 
     {
      write(
      "�ʶ��м���˵��:лл����Ҵ�ɨ����������......\n"
      "��.................\n\n"
      "һ��̾Ϣ֮��ʶ�����˵������ʵ��Ҳ�Ǻܰ�Ǭ���ģ������������֣���������\n"
      "������ȥ��ɨ��������Ȼ���ɨ�ú�Ǭ��������������˶��������ǻ��ø�\n"
      "��ǰһ�������࣬�ѵ���Ҫ�������ɨ�����������ⲻ��һ���α��ĺð취��\n"
      "������������ˣ��һ��Ƿǳ���лл�㡣\n"
      "˵����Щ�����ʶ���������̾����������Ĳˡ�\n\n");
     
     
      this_player()->set_temp("fat_quest",(["ask":0,
                                            "diet":0,
                                            "meat":0,
                                            "fish":0,
                                            "cook":0,
                                           ]));
      call_out("recover",10,this_player());
     return 1;
     }
  else return 1;
    }
  else  {
    write(
    "��ȷ��Ҫ��������ɨ��?\n");
    return 1;    
        }
}
int recover()
  { 
   write(
   "�ʶ�̧ͷ������һ����˵�������������������ˣ���֪����Ը��Ը�����\n"
   "�ҽ���ҵĿ���(trouble)��?\n");
   this_player()->set_temp("fat_quest/ask",1);
   }   
int do_consider(string arg)
{
  if ( !arg || arg != "meat")
  return notify_fail(
  "����ʲ��?\n"  );
  if ((int)this_player()->query_temp("fat_quest/meat")==2 && present("cooker")) {
  write(
  "�ʶ�˵��: ԭ����ˣ��������������ֹ�Ӫ��ҵ�������ǲ���������õ�.....\n"
  "˵�꣬�ʶ��ֿ�ʼ�����̾........\n"
  "���룬��ʵ����һ�����ѵ�����ƾ����ǻ��Ǻ��Ѵ���ġ�����\Ӧ\��\��\��\����\n"
  "��һͬ������\n");
  this_player()->set_temp("fat_quest/ask",2);
  return 1;
  }
  else return 0;
  }
 int do_suggest(string arg)
 {
 if (!arg || arg != "fish" )
 return notify_fail(
 "����ʲ��?\n" );
 if ((int)this_player()->query_temp("fat_quest/fish")==1 && present("cooker"))  {
 write(
 "�ʶ�˵��: ����ȥ�������������Ǹ������⣬�����Ҵ���û���Թ���Ҳ�����\n"
 "����ȥ�Ѳ����û���������\n");
 return 1;
 }
 else { write(
 "����Ҫ��ʲ��?\n");
 return 1;
}}
int clean_up() { return 0; }