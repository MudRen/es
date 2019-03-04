#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("spirit ball","ÙãÁéÖé");
        add( "id" , ({ "ball" }) );
        set_short( "ÙãÁéÖé");
        set_long(@C_LONG
Ò»¿ÅÄ«ºÚÉ«µÄÔ²Çò£¬ÓÌÈçÒ»Á£ºÚÕäÖé¡£
C_LONG  );      
        set("unit","¿Å");
        set("weight",50);
        set("no_sale",1);
        set("spiritball",1);
        set("master","???");
        set("value", ({1, "silver"}) );
}
