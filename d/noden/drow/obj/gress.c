#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("snake herb","���Ѳ�");
    add("id",({"herb"}) );
    set_short("���Ѳ�");
    set_long(
@C_LONG
    ���������������Աߵ�һ������С�ݣ���������һ���񺫹��ݣ�
��˵�ںڰ��������У������ܽ�����С�ݺ�ĳЩҩ�Ļ�ϣ��Ƴ�һ��
ҩ�ۣ����ڴ������ܣ��ܷ�ֹ���ߵ����롣
C_LONG
            );
    set("unit","��");
    set("weight",18); 
    set("value", ({ 20, "silver" }));
    set( "no_sale",1); 
}    
