
#include <mudlib.h>

inherit ROOM;

int bushes = 1;

void create()
{
	::create();
   set_short("ɽ��");
	set_long( @LONG_DESCRIPTION
��������һ��һЩ�Ͱ�ɽ����ɵ�������ϣ�����ĵ��������
���ܴ���ƽ���Ķ̲�Ƥ����\����Ŀ������ɽ�𣬼������(tree)
ɢ����ɽ���ϡ�
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
          "east" : "/d/eastland/15,12.east" ]) );
   set( "original", "/d/eastland/14,12" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
   set( "x_coordinate", 14 );
   set( "y_coordinate", 12 );
   set( "c_item_desc", ([
        "tree" : "������������Ĵ�����\n",
        "root" : "@@root_stat" ]) );
   set( "search_desc", ([
        "tree" : "����ϸ��������Щ��ľ, ���������������ľ������(root)�е����ء�\n",
        "root" : "@@search_root" ]) );
	reset();
}

void init()
{
   add_action( "push_bushes", "push" );
}

int push_bushes(string arg)
{
   if( !arg || arg != "bushes" )
   return notify_fail( "�������ǰ�����˼��¡�\n" );
   write( "��ѲݴԲ�����\n" );
   bushes = 0;
   return 1;
}

string search_root()
{
   if( !bushes ) {
   this_object()->set("exits/hole","/d/eastland/ianyeu/hole");
     return "������ϸ����Ѱ�ݴ�֮�������ʱ, ������һ����Ѩ(hole)!\n";
   }
   return "����ϸ����������, ���ǲݴ�(bushes)̫���ˡ�\n"
          "����\��Ӧ���Ȱ������ƿ�(push)��\n";
}

string root_stat()
{
   if( !bushes )
   return "��ͨ������, �����㿴���������Ĳݴ����ƺ��е�Ź֡�\n";
   else return "��ͨ��������\n";
}

void reset()
{
   delete("exits/hole");
   ::reset();
}
