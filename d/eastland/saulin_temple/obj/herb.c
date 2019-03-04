#include <mudlib.h>

inherit OBJECT;

void create()
{
	set("packked",0);
	set_name( "Herb of re-live", "������" );
	add( "id", ({ "herb" }) );
	set_short( "������" );
	set_long(@C_LONG
����һ������ݣ������ڱ����������ˣ������Ե���Щ��\ή������
�øϿ��������(pack)����(plant)��ȥ���ٽ�(water)Щˮ��
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 5 );
	set( "packked", 0 );
	set( "value", ({ 1, "copper" }) );
//	set( "no_sale", 1 );
	set( "useless", 1 );
}

void init()
{
	add_action( "do_plant", "plant" );
	add_action( "do_pack", "pack" );
	call_out( "mess_up", 30, this_object(), 1 );
}

int do_pack(string arg)
{
    if( !arg || arg!="herb" )
    	return notify_fail( can_read_chinese() ?
    		"��ʲ�᣿\n" : "pack what?\n"
    	);
    if( query("packked") )
    	return notify_fail( "����������Ѿ������ˡ�\n");
    tell_object(this_player(),
     	"����ϸ�İѻ������������ã�����������ά�ֳ�һ���ʱ�䡣\n"
    );
	set("packked", 1);
    return 1;
}

int do_plant(string arg)
{
	object obj;

	obj=environment( this_player() );
   	if( !arg || arg != "herb" )
    	return notify_fail("��ʲ�᣿\n");
	if( (string)obj->query("short")=="ҩ��" ) {
	  if( query("packked") ) {
        tell_object(this_player(),
                    "��ѻ���������ҩ���ϣ����������Ǵ�ͷɥ���ġ�\n"
		);
		this_player()->set_temp("herb_quest/step",1);
	  } else
        tell_object(this_player(),
            "�����û�аѻ����ݰ��ã����Ѿ��������Ļ���ˣ���ֻ�ð������ˡ�\n"
        );
      remove();
	} else
       tell_object(this_player(),
         "��Ҫ�ѻ��������������ȷ����\n"
       );
    return 1;
}

void mess_up(object what, int first)
{
    object owner;
    
    owner = environment(what);
    if( what->query("packked") && first ) {
    	call_out( "mess_up", 100, what, !first );
    	return;
    }
    if( living(owner) )
      tell_object( owner,  
		"��! �����ݿ�\�ˣ���ֻ�ð������ˡ�\n" 
      );
    what->remove();
}
