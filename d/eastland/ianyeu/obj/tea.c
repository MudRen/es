inherit "/d/noden/asterism/item/drink.c" ;

void create()
{
    ::create();
    seteuid(getuid());
    set_name( "tea", "���ݴ�" );
    set_short( "���ݴ�" );
    set_long(
        "�㿴��һ��ɫ�����, �����嵭���˵��̲衣�����̲�ס���������\n" );
    set( "unit", "��" );
    set( "container", 0 );
    set( "tp", 60 );
    set( "hp", 5 );
    set( "value",({ 100, "silver" }) ) ;
    set( "amount", 0 );
    set( "c_succ", "�����һ�����ݴ�, һ������ͣ춿ڼ�, �þò�ɢ��\n" );
   set( "c_osucc", "$CN������һ�����ݴ���\n" );
}
