#include "../oldcat.h"

inherit ROOM;

int showed;
void create()
{
	::create();
    set_short( "�������");
	set_long( 
@LONG
һ�����������ȣ�һ��ڻ�����һλ�������еİ�������ʿ����һ��֪����Ұ
�ޣ����ָ߾�����ì�̵������˻��Ķ�����(unicorn)����������ͨ���ҵ���Ͽ�
ͨ�����������ͨ����Ժ��
LONG
	);
set( "exits", ([
     "east" : OTEMP"temple20",
     "north" : OTEMP"temple12",
     "southwest" : OTEMP"temple6"
     ]) );
set( "item_desc", ([
     "unicorn":"@@look_unicorn",
     ]) );
reset();
}

string look_unicorn()
{
  object ob;

  if (present("unicorn",this_object()) || showed)
    return "һֻ���ں���ʿս���Ķ����ޡ�\n";
  write("�㿴����Ψ��ΨФ�Ķ�����............\n");
  write("�����������㷢��������ľ���Խ��Խ��.........\n");
  write("����Ĳ��Ծ���æ���۾�������.....���ſ�ʱ���� ! �����޾�Ȼ������ǰ��\n");
  ob=new(OMONSTER"unicorn");
  ob->move(this_object());
  showed=1;
  return "\n"; 
}

void reset()
{
  ::reset();
  showed=0;
}
