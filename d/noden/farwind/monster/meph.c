#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
   set_name( "Meph", "��ɴ���ϰ�Ī��" );
   add( "id", ({ "owner", "boss" }) );
   set_short( "Ī��" );
	set_long(@C_LONG
    Ī����һ����Լ��ʮ������, ��������һ��û�н�ֵĿ�����,
�����˵ض���, �����˴�һ��������, ϣ�����������˾��ɾ�����
���������������(rent)�����
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
   set( "inquiry", ([
         "rent" : 
@LONG
����, �����ȿ����ǵļ�Ŀ��(menu),
����������������ṩ֮���; ����������ӹ�Ļ�, ������
��ɻ������˻�(return)����, ����, ��ָ, ������Բ����,
ÿ�����˻���1500����. ����������, ����㲻���, ��ָ��
����Բ���ǲ��ܴ����봢���.
LONG
     ]) );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "�̵��ϰ��Ц��: л��! �׳�!\n"
        "( �̵��ϰ��"+item->query("c_name")+"������! )\n" );
   item->remove();
   return 1;
}

void init()
{
   add_action("do_buy", "buy");
   add_action("do_return", "return");
}

int do_buy(string str)
{
   object ring, globe;

   if( str == "ring" || str == "wedding ring" ) {
       if( present("wedding ring",this_player()) ) {
       printf( "�ϰ�˵: ����ָһ����ֻ��Ҫһֻ!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<5000 ) {
       printf( "�ϰ�˵: �������㹻������������!\n" );
       return 1;
       }

       ring = new( "/d/noden/farwind/wedding_obj/wedding_ring" );

       printf( "������һֻ����ָ.\n" );
       ring->move(this_player());
       this_player()->credit("silver", -5000);
       return 1;
   }
   if( str == "globe" || str == "wedding globe" ) {
       if( present("wedding globe",this_player()) ) {
       printf( "�ϰ�˵: ��黤��Բ��һ����ֻ��Ҫһ��!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<8000 ) {
       printf( "�ϰ�˵: �������㹻������������!\n" );
       return 1;
       }

        globe = new( "/d/noden/farwind/wedding_obj/wedding_globe" );

       printf( "������һ����黤��Բ��.\n" );
       globe->move(this_player());
       this_player()->credit("silver", -8000);
       return 1;
   }
   if( str != "ring" && str != "wedding ring" &&
       str != "globe" && str != "wedding globe" &&
       this_player()->query("spouse") ) {
   printf( "�ϰ�ŭ��: �����ػ���?\n" );
   return 1;
   }
}

int do_return(string str)
{
   object player, obj;
   string armor;

   player = this_player();

   if( !str || str =="" ) return notify_fail( "��Ҫ��ʲ�ᶫ��?\n" );

   if ( sscanf(str, "%s", armor)==1 ) {
     obj = present(armor,player);

   if( !obj ) return notify_fail( "��û���ⶫ��!\n" );
   if( !obj->query("wedding_obj") )
      return notify_fail( "Ī��˵: �Բ���! ����������겻����!\n" );
   if( !this_player()->query("spouse") )
      return notify_fail( "Ī��˵: �㻹û��鰡! ����������!\n" );
   tell_room( environment(),
        "Ī��˵: �˻�Ѻ��1500����, лл�ݹ�.\n"
         "( Ī�ɰ�"+obj->query("short")+"�������ȴ���ϴ )\n" );
   player->credit("silver", 1500);
   obj->remove();
   return 1;
   }
}
