# Tenma 72-2660 SMPS Repair


## 2022-10-02 Stream Notes

Removed transformer, but it was fine. Short is definitely in the DC section.

I started with 100 mA while looking with a thermal camera, but couldn't see anything getting hot.

I got up to an amp and the only place that showed a blip on the camera was under the toroid near the output terminals.

Removed that and saw some questionable soldering but no real failure point. michael701 suggested to remove the FET and see if the short goes with it.

It did.

Not only that, but measuring the FET out of circuit showed it was ded.

THe questionable FET is the [TCPA8053-H]](https://toshiba.semicon-storage.com/us/semiconductor/product/mosfets/12v-300v-mosfets/detail.TPCA8053-H.html). This FET is obsolete. Toshiba recommends replacing it with a [TPH9R506PL](https://toshiba.semicon-storage.com/info/lookup.jsp?pid=TPH9R506PL&region=ncsa&lang=en_us). It has a lower Rds-on, but it is the same pacakge. So I'm blindly buying some.