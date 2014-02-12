zadane obrażenia = zaokr(sila przeciwnika ∗ (zdrowie przeciwnika/100) ∗ (1.0 + bron przeciwnika) ∗ (1.0 − nasza zbroja))



attack_effectiveness(character* Y, character* X) = (Y->getStrengh())*((Y->getHealth())/100)*(1.0 + Y->getWeapon())*(1.0 - X->getArmor());

new_health(character* Y) = X->getHealth() - attack_effectiveness(Y, X);


