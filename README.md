# C Range Library

Bu, belirli bir aralık üzerinde işlem yapabilen bir C kütüphanesidir. Aralıklar üzerinde yinelemeler (iteration), filtreleme, dönüştürme (map) ve azaltma (reduce) işlemleri gerçekleştirilebilir. Bu kütüphane, taşınabilir ve genel amaçlı bir yapı sunar ve tek başlık (one-header) formatında yazılmıştır.

## Özellikler

- **Taşınabilir:** Tek bir header dosyasında yazılmıştır. Bu sayede farklı projelere kolayca entegre edilebilir.
- **Kolay Kullanım:** Range (aralık) veri yapıları üzerinde işlem yapmak için basit ve anlaşılır API sağlar.
- **Performans:** Verimlilik göz önünde bulundurularak yazılmıştır.
- **Esneklik:** Farklı işlemler için genel fonksiyonlar (map, filter, reduce) kullanılarak işlemlerinize göre kolayca özelleştirilebilir.

## Kullanım

### Başlangıç

Bu kütüphaneyi kullanmaya başlamak için önce `crange.h` dosyasını projene dahil etmen yeterlidir.

```c
#include "crange.h"
```

### Aralık Oluşturma

Aralık (Range) oluşturmak için `range_create` fonksiyonunu kullanabilirsiniz. Bu fonksiyon, başlangıç, bitiş ve adım parametrelerini alarak bir aralık döndürecektir.

```c
Range r = range_create(0, 10, 2);
```

### Aralık Üzerinde Dönme (Iteration)

Aralık üzerinde işlem yapmak için `range_iterate` fonksiyonunu kullanabilirsiniz. Bu fonksiyon her bir aralık elemanını parametre olarak alır ve belirtilen callback fonksiyonunu çalıştırır.

```c
range_iterate(r, callback);
```

### Aralık Üzerinde Filtreleme (Filter)

Aralık üzerinde bir koşula göre elemanları filtrelemek için `range_filter` fonksiyonunu kullanabilirsiniz. Bu fonksiyon, verilen predicate fonksiyonu ile aralık elemanlarını filtreler ve sonrasında belirtilen callback fonksiyonunu çalıştırır.

```c
range_filter(r, predicate, callback);
```

### Aralık Üzerinde Azaltma (Reduce)

Aralık üzerinde bir işlemi tekrarlayarak tek bir değere indirgemek için `reduce_range` fonksiyonunu kullanabilirsiniz. Bu fonksiyon, belirli bir başlangıç değeri ile her bir aralık elemanını işleyerek tek bir değer döndürür.

```c
int result = reduce_range(r, operation, initial);
```

### Aralık Üzerinde Dönüştürme (Map)

Aralık üzerinde bir dönüşüm yapmak için `map_range` fonksiyonunu kullanabilirsiniz. Bu fonksiyon, her aralık elemanı için bir dönüşüm işlemi yapar ve dönüşüm sonuçlarını içeren yeni bir dizi döndürür.

```c
int* result = map_range(r, callback);
```

## Katkı Kılavuzu (Contributing Guidelines)

Eğer bu projeye katkıda bulunmak isterseniz, lütfen aşağıdaki adımları izleyin:

1. Fork Yapın: Projeyi GitHub üzerinde fork edin.
2. Değişiklik Yapın: Kendi kopyanızda istediğiniz değişiklikleri yapın.
3. Pull Request Gönderin: Değişikliklerinizi bu projeye dahil edilmesi için pull request olarak gönderin. Katkılarınız için teşekkür ederiz!
4. Kodunuzu Açık Kaynak Yapın: Lütfen yaptığınız değişikliklerin açık kaynak olmasını sağlayın. Bu, yazılımın herkes tarafından erişilebilir ve geliştirilebilir olmasını garanti eder.
