#include "../echobomber.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "�������̵�" );
	set_long( @C_LONG
�����߽����������,�㷢������Ӧ����һ���̵�,Ȼ����ȴ��������,��Ϊ������
���˲��ڹ�̨������.ֻ�������õ��������ȫ��������.��ǽ�ϵ�ȼ��һ�ѻ��,΢��
�Ļ���ʹ�����Եÿֲ�.���˸о�����������ڵ�һ��.
C_LONG
);
	set( "exits", ([ 
	  "out" : Deathland"/main/d11", 
	]) );
	::reset();
}
void init()
{
   ::init();
   add_action("to_sell","sell");
}

int to_sell(string str)
{
    write("�ϰ�¶��а���Ц��,˵: ��������������,��......\n");
    if ( (int)this_player()->query("alignment") >= 0 ) {
      write("�������Ӧ�ð�����������˰�!\n");
	  // rating 1,3 mean 1/3 By Kyoko.
      this_object()->set("rating", ({ 1, 3 }) );
    } else {
      write("а��ļһ�,��ϲ��,������������,����...\n");
      this_object()->set("rating", ({ 2, 5 }) );   
    }
    return ::sell(str);
}
