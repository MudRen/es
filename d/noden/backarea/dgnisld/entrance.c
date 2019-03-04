#include "dgnisld.h"

inherit ROOM;


int cropps;
void create()
{
	::create();
	cropps = 0;
	set( "cropp",1);
	set( "outside" ,"dgnisld" ) ;
   set_short(
	           "���������" ) ;
	set_long(
	    "������������ڣ�����Կ���һ������������ŵĸ�ʾ(sign)��\n"
	"�����ƺ���һƬ���ԭ(campo)����һ��С��ͨ����������ɭ��(forest)\n"
	"����������һ�Ը���Ũ�ܵĲݴ�(brush)��\n"
        ) ;

	set( "item_desc", ([
	     "sign" : 
  "���Ÿ�ʾд����\n"
  "��������������������������������������������������������������������\n"
  "��ӭ����������\n"
  "  �⵺���������͹�ķ������Ͻ������ȴ�������˿�����������Ŀ��������\n"
  "��ԭ�����󡢺�����ɭ�֡���ɽ�ȵ��Σ�����������Σ�գ�Ҳ��˱�����һ\n"
  "Щԭʼ����˴���Ϊ���̣���������δ�������������������һ�����ص�\n"
  "ɫ�ʡ���С����Щ�ױ�����ʳ�Կ��������ǿ��������ֿܵ�֮ǰ�Ͱ���һ��\n"
  "�̵�����һ�����塪������ʿ��ס�����������Ψһ�������幵ͨ������\n"
  "���������Ǹ����������㣬�������ǳ����������ǵ�һԱ��\n"
  "                                            һ�̹ݹ�����  ��������\n"
  "��������������������������������������������������������������������\n",
           "brush" : "ʮ��ï�ܵĲݴԣ��ƺ��������ˮ���㡣\n",
           "forest": "�ܴ��ɭ�֣�����������ɭ�ֲֿ���\n",
           "campo" : "һ���޼ʵĲ�ԭ�������Ӳݴ�����\n",
           ]) );
    set( "objects", ([
        "bahamut" : "/u/k/kyoko/FF-V/bahamut",   ]) );
	set( "exits", ([
	   "northwest"    : DGNISLD"forest1-10",
	       "north"    : DGNISLD"campo10-1",        ]) );
   reset();
}

void init()
{
        add_action("enter_hole","enter");
}

int to_find_cropp(string str)
{
      if ( !str || str!="brush" )
        write("You can't cropp it!\n");
      else {
        if (cropps==0) {
          cropps=1;
          add( "item_desc",([ 
                 "hole" : "һ��С����������С��һ��ֻ����һ��ͨ��������\n"
                          "������ΣΣ��׹��������ʱ���������\n",              
                "brush" : "��ݴԿ�����������������������һ̣��Ϳ��\n",            
                         ]) );
          write(
            "�������ݴ�ʱ�������˵ط���һ��С��(hole)��������С��ֻ\n"
            "����һ��ͨ��(enter) ��������ΣΣ��׹��������ʱ���������\n");
          say(
            this_player()->query("c_cap_name")+"����һЩ������\n");
        }
        else 
          write("They have been cropped!\n");
      }
      return 1;
}

int enter_hole(string str)
{        
         if ( !str || str=="" )
           write("enter what ?\n");
         else if ( str!="hole" )
           write("There are no "+str+" here!\n");
         else if (cropps==1){
           write("You climb into the hole and walk forward. The hole is\n"
                 "broken when you enter it. You enter a very dark place.\n"  );
           say( this_player()->query("cap_name")+
                " enter a hole and disappear.\n");
           cropps = 2;
           add( "item_desc",([
                "hole" : "����̽ͷ�����濴���㷢���ⶴ�Ѿ����ˣ�\n" ])  );
                                 
           this_player()->move_player(DGNISLD"hole1", "", "") ;
         }
         else if (cropps==2)
           write( !can_read_chinese() ? 
             "The hole has been broken!\n":"�ⶴ�Ѿ����ˣ�\n");
         return 1;
}

int get_cropps()
{
         return cropps;
}
         
void reset()
{
    ::reset();
    cropps=0;
}
