#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short("��������" );
	set_long(
@LONG
�������������⣬���µ������챦���ܶ��������ҵĵ��������ý���Щ��ͨ
�����顢��觡���,����ʯ�ȵȣ�����������������ʵ����̫���ˣ���������
������ǿ�ǵ���Ҳ�ǲ���ȫ����
LONG
	);
	set( "exits", ([
	     "east" : OTEMP"palace4",
	    ]) );
        set("pre_exit_func", ([
             "east":"to_east"
             ]) );
        set("search_desc",([
            "here":"@@to_search_here"
            ]) );
        set("light",1);
        reset(); 
}

string to_search_here()
{
  string str;
  object ob;

  if (be_get)
    str="�����ⱦ�����Ұ��죬�Ҳ��������������õĶ�����\n";
  else {
    str="�����ⱦ������������һ��̴ľ�����У��ҵ�һ����ˮ�顣\n";
    ob=new(OOBJ"waterball");
    ob->move(this_object());
    be_get=1; }
  return str;
}

int to_east()
{
  printf("\n�㴩��һƬ��⣬�뿪���⡣\n");
  return 0;
}

void reset()
{
  ::reset();
  be_get=0;
}
void init()
{
   if(this_player()) this_player()->set_explore("eastland#39");
}
