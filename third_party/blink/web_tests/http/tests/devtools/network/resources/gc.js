// This file was copied from third_party/blink/web_tests/resources/gc.js
// If there is no window.gc() already defined, define one using the best
// method we can find.
// The slow fallback should not hit in the actual test environment.
if (!window.gc)
{
    window.gc = function()
    {
        if (window.GCController)
            return GCController.collectAll();
        function gcRec(n) {
            if (n < 1)
                return {};
            var temp = {i: "ab" + i + (i / 100000)};
            temp += "foo";
            gcRec(n-1);
        }
        for (var i = 0; i < 10000; i++)
            gcRec(10);
    }
}
